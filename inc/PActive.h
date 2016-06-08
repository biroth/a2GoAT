#ifndef __PActive_h__
#define __PActive_h__

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

#include "GTreeManager.h"
#include "PPhysics.h"

class	PActive  : public PPhysics
{
private:
    TH1*	TaggerAllHits;
    TH1*	TaggerSingles;
    TH1*	TaggerDoubles;
    TH1*	TaggerAccScal;
    TH1*	VupromAccScal;

    TH1*	NePi_Time;
    TH1*	NePi_TCut;
    GH3*	NePi_EkEHMa;
    GH3*	NePi_EkESMa;
    GH3*	NePi_TiEHMa;
    GH3*	NePi_TiESMa;

    TH1*	NePi_Time_OA;
    TH1*	NePi_TCut_OA;
    GH3*	NePi_EkEHMa_OA;
    GH3*	NePi_EkESMa_OA;
    GH3*	NePi_TiEHMa_OA;
    GH3*	NePi_TiESMa_OA;

    GH3*	NePi_EkOAMa;
    GH3*	NePi_EkOAMa_AT;

    GH1*	IM;
    GH1*	MM;

    TH2*    TimevsTSum;
    TH2*    TimevsTSum_AT;

    Int_t APPT_ADC[16];
    Int_t APPT_TDC[16];

    Double_t APPT_ADC_Ped[16];
    Double_t APPT_ADC_Gain[16];
    Double_t APPT_TDC_Off[16];
    Double_t APPT_TDC_Gain[16];

    Double_t APPT_Scale;

    Double_t APPT_Ener[15];
    Double_t APPT_Time[15];
    Double_t APPT_ESumH;
    Double_t APPT_ESumS;
    Double_t APPT_TSum;

    TH1D*   hAPPT_Ener[15];
    TH1D*   hAPPT_Time[15];
    TH2D*   hAPPT_EvsT[15];

    TH1D*   hAPPT_TSum;
    TH1D*   hAPPT_ESumH;
    TH2D*   hAPPT_EHvsT;
    TH1D*   hAPPT_ESumS;
    TH2D*   hAPPT_ESvsT;

    TH2D*   hAPPT_EHvsES;
    TH2D*   hAPPT_EHvsES_NePi;

    Double_t OACut;

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();
			
public:
    PActive();
    virtual ~PActive();
    virtual Bool_t  Init();
    Bool_t InitOpeningAngle();
    Bool_t InitActiveChannel();
    Bool_t InitActiveScale();

};
#endif
