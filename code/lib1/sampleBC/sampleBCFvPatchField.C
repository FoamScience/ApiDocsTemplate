#include "sampleBCFvPatchField.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"

template<class Type>
Foam::scalar Foam::sampleBCFvPatchField<Type>::t() const
{
    return this->db().time().timeOutputValue();
}

template<class Type>
Foam::sampleBCFvPatchField<Type>::
sampleBCFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF
)
:
    fixedValueFvPatchField<Type>(p, iF),
    scalarData_(0),
    data_(Zero),
    fieldData_(p.size(), Zero),
    timeVsData_(),
    wordData_("wordDefault"),
    labelData_(-1),
    boolData_(false)
{
}


template<class Type>
Foam::sampleBCFvPatchField<Type>::
sampleBCFvPatchField
(
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<Type>(p, iF),
    scalarData_(dict.get<scalar>("scalarData")),
    data_(dict.get<Type>("data")),
    fieldData_("fieldData", dict, p.size()),
    timeVsData_(Function1<Type>::New("timeVsData", dict)),
    wordData_(dict.getOrDefault<word>("wordName", "wordDefault")),
    labelData_(-1),
    boolData_(false)
{
    fixedValueFvPatchField<Type>::evaluate();
}


template<class Type>
Foam::sampleBCFvPatchField<Type>::
sampleBCFvPatchField
(
    const sampleBCFvPatchField<Type>& ptf,
    const fvPatch& p,
    const DimensionedField<Type, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchField<Type>(ptf, p, iF, mapper),
    scalarData_(ptf.scalarData_),
    data_(ptf.data_),
    fieldData_(ptf.fieldData_, mapper),
    timeVsData_(ptf.timeVsData_.clone()),
    wordData_(ptf.wordData_),
    labelData_(-1),
    boolData_(ptf.boolData_)
{}


template<class Type>
Foam::sampleBCFvPatchField<Type>::
sampleBCFvPatchField
(
    const sampleBCFvPatchField<Type>& ptf
)
:
    fixedValueFvPatchField<Type>(ptf),
    scalarData_(ptf.scalarData_),
    data_(ptf.data_),
    fieldData_(ptf.fieldData_),
    timeVsData_(ptf.timeVsData_.clone()),
    wordData_(ptf.wordData_),
    labelData_(-1),
    boolData_(ptf.boolData_)
{}


template<class Type>
Foam::sampleBCFvPatchField<Type>::
sampleBCFvPatchField
(
    const sampleBCFvPatchField<Type>& ptf,
    const DimensionedField<Type, volMesh>& iF
)
:
    fixedValueFvPatchField<Type>(ptf, iF),
    scalarData_(ptf.scalarData_),
    data_(ptf.data_),
    fieldData_(ptf.fieldData_),
    timeVsData_(ptf.timeVsData_.clone()),
    wordData_(ptf.wordData_),
    labelData_(-1),
    boolData_(ptf.boolData_)
{}


template<class Type>
void Foam::sampleBCFvPatchField<Type>::autoMap
(
    const fvPatchFieldMapper& m
)
{
    fixedValueFvPatchField<Type>::autoMap(m);
    fieldData_.autoMap(m);
}


template<class Type>
void Foam::sampleBCFvPatchField<Type>::rmap
(
    const fvPatchField<Type>& ptf,
    const labelList& addr
)
{
    fixedValueFvPatchField<Type>::rmap(ptf, addr);

    const sampleBCFvPatchField<Type>& tiptf =
        refCast<const sampleBCFvPatchField<Type>>(ptf);

    fieldData_.rmap(tiptf.fieldData_, addr);
}


template<class Type>
void Foam::sampleBCFvPatchField<Type>::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    fixedValueFvPatchField<Type>::operator==
    (
        data_
      + fieldData_
      + scalarData_*timeVsData_->value(t())
    );


    fixedValueFvPatchField<Type>::updateCoeffs();
}


template<class Type>
void Foam::sampleBCFvPatchField<Type>::write
(
    Ostream& os
) const
{
    fvPatchField<Type>::write(os);
    os.writeEntry("scalarData", scalarData_);
    os.writeEntry("data", data_);
    fieldData_.writeEntry("fieldData", os);
    timeVsData_->writeData(os);
    os.writeEntry("wordData", wordData_);
    this->writeEntry("value", os);
}
