#!/usr/bin/env bash

# Usage: ./generate-docs.sh /absolute/path/to/src /absolute/path/to/where/docs/will/be
#
# Note, compile_commands.json databases must be populated prior to running this script

if [[ -z ${1} ]] || [[ -z ${2} ]]; then
echo "Usage: ./generate-docs.sh /absolute/path/to/src /absolute/path/to/where/docs/will/be"
exit 1
fi

src="${1}"
if [ ! "${src:0:1}" = "/" ]; then
    echo "Source code path needs to be absolute."
    exit 1
fi
api="${2}"
if [ ! "${api:0:1}" = "/" ]; then
    echo "API docs path needs to be absolute."
    exit 1
fi

# Checking dependencies
for cmd in jq mdformat; do 
if command -v "$cmd" >/dev/null 2>&1 ; then
    echo "$("$cmd" --version)"
else
    echo "$cmd not found"
    exit 1
fi
done

set -e
libs=$(find "$src" -maxdepth 1 -mindepth 1 -type d )
for lib in $libs; do
    cd "$lib" || exit
    libname=$(basename "$lib")
    sources=$(jq -r '.[].file' "$lib"/compile_commands.json)
    headers=$(find . -type f -not -path "./lnInclude/*" -name "*[H]")
    includes=$(find . -type d -name lnInclude -exec echo "-I{}" \;)
    args=$(jq '.[].arguments | map(select(. | match("-[IDs]")))' compile_commands.json | jq -rs 'flatten(1) | unique | join(" ")')
    mkdir -p "$api/$libname" "$lib"
    output=$(realpath --relative-to="$PWD" "$api/$libname")
    sr=$(realpath --relative-to="$PWD" "$lib")
    echo "Generating docs for $lib"
    ~/repos/hyde/build/hyde --ignore-deprecation-warnings --index-filename=_index.md\
        -auto-toolchain-includes -hyde-yaml-dir="$output" \
        -hyde-update \
        -hyde-src-root="$lib" \
        ${headers} ${sources} \
        -- ${args} ${includes} > /dev/null
    sed -i "s/^title:.*/title: $libname/g" "$api/$libname"/_index.md
    cd - > /dev/null || exit
done

scriptdir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
find $api -type f -name "*md" -exec python3 $scriptdir/process-fm.py {} ${src} ${api} \; -exec mdformat {} \;
find $api -type f -name "*md" -exec sed -i 's/\\ \([abtnvfre]\)/\\\1/g' {} \;
