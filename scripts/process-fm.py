#!/usr/bin/python3

import sys, io, os, git
import frontmatter as fm

def processContributorsList(contribs):
    """Split comma-seperated list of contributors"""
    res = []
    for c in contribs:
        for i in c.split(','):
            res.append(i.strip())
    return res

def getGitRepo(filename):
    """Get root folder of code git repository"""
    return 
    #return grepo.git.rev_parse("--show-toplevel")

print(f"Processing {sys.argv[1]}")
post = fm.load(sys.argv[1])

# If a directory, change name to directory name
if post["layout"] == "directory" or post["layout"] == "library":
    dirnm = os.path.basename(os.path.dirname(sys.argv[1]))
    if dirnm != "api":
        post["title"] = dirnm

# If not a hyde file, do not continue but write
if "hyde" not in post.keys():
    b = io.BytesIO()
    fm.dump(post, b)
    with open(sys.argv[1], "wb") as f:
        f.write(b.getbuffer())
    exit(0)

# Produce links for source files
if "defined_in_file" in post["hyde"].keys() and post["hyde"]["defined_in_file"] != "":
    repo = git.Repo(sys.argv[2], search_parent_directories=True)
    root = repo.git.rev_parse('--show-toplevel')
    remote = repo.remote().url
    branch = repo.active_branch.name
    relpath = os.path.relpath(sys.argv[2]+"/"+post["hyde"]["defined_in_file"], root)
    remotepath = f"{remote}/blob/{branch}/{relpath}"
    post["hyde"]["defined_in_file"] = remotepath

# Consolidate namespace
if "namespace" in post["hyde"].keys():
    post["api_namespaces"] = ["::".join(post["hyde"]["namespace"])]

# Convert owners to Hugo authors
if "owner" in post["hyde"].keys():
    own=post["hyde"]["owner"]
    if own == "__INLINED__":
        ner = post["hyde"]["inline"]["owner"]
        post["contributors"] = ner.split(',') if isinstance(ner, str) else processContributorsList(ner)
    elif own == "__OPTIONAL__":
        pass
    else:
        ner = post["hyde"]["owner"]
        post["contributors"] = ner.split(',') if isinstance(ner, str) else processContributorsList(ner)

# Convert tags to Hugo api_tags
if "tags" in post["hyde"].keys():
    if len(post["hyde"]["tags"]) > 0:
        post["api_tags"] = list(post["hyde"]["tags"])

b = io.BytesIO()
fm.dump(post, b)
with open(sys.argv[1], "wb") as f:
    f.write(b.getbuffer())
