---
api_tags:
  - method
contributors:
  - __MISSING__
hyde:
  brief: __INLINED__
  defined_in_file: https://github.com/FoamScience/ApiDocsTemplate/blob/main/code/sampleBC/sampleBCFvPatchField.H
  inline:
    brief: _multiple descriptions_
  overloads:
    tmp<fvPatchField<Type>> clone() const:
      description: __INLINED__
      inline:
        description:
          - '- Construct and return a clone'
      key: tmp<fvPatchField<Type>> clone() const
      return: __OPTIONAL__
      signature_with_names: tmp<fvPatchField<Type>> clone() const
    tmp<fvPatchField<Type>> clone(const DimensionedField<Type, Foam::volMesh> &) const:
      arguments:
        - description: __OPTIONAL__
          name: iF
          type: const DimensionedField<Type, Foam::volMesh> &
      description: __INLINED__
      inline:
        description:
          - '- Construct and return a clone setting internal field reference'
      key: tmp<fvPatchField<Type>> clone(const DimensionedField<Type, Foam::volMesh>
        &) const
      return: __OPTIONAL__
      signature_with_names: tmp<fvPatchField<Type>> clone(const DimensionedField<Type,
        Foam::volMesh> & iF) const
  owner: __MISSING__
  tags:
    - method
layout: method
title: clone
---
