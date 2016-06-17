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
    TH1*	 TaggerAllHits;
    TH1*	 TaggerSingles;
    TH1*	 TaggerDoubles;
    TH1*	 TaggerAccScal;
    TH1*	 VupromAccScal;

    GH1*	 hIM;
    GH1*	 hMM;

    TH1*	 hTime;
    TH1*	 hTCut;
    GH3*	 hEkThMa;
    GH3*	 hEkEHMa;
    GH3*	 hEkESMa;
    GH3*	 hTiEHMa;
    GH3*	 hTiESMa;

    TH1*	 hTime_OA;
    TH1*	 hTCut_OA;
    GH3*	 hEkThMa_OA;
    GH3*	 hEkEHMa_OA;
    GH3*	 hEkESMa_OA;
    GH3*	 hTiEHMa_OA;
    GH3*	 hTiESMa_OA;

    TH1*	 hTime_Ch;
    TH1*	 hTCut_Ch;
    GH3*	 hEkThMa_Ch;
    GH3*	 hEkEHMa_Ch;
    GH3*	 hEkESMa_Ch;
    GH3*	 hTiEHMa_Ch;
    GH3*	 hTiESMa_Ch;

    GH3*	 hEkOAMa;
    GH3*	 hEkOAMa_AT;

    TH2*     hTimevsTSum;
    TH2*     hTimevsTSum_AT;

    Int_t    APPT_ADC[16];
    Int_t    APPT_TDC[16];

    Double_t APPT_ADC_Ped[16];
    Double_t APPT_ADC_Gain[16];
    Double_t APPT_TDC_Off[16];
    Double_t APPT_TDC_Gain[16];
    Bool_t   APPT_Use[16];

    Double_t APPT_Scale;

    Double_t APPT_Ener[15];
    Double_t APPT_Time[15];
    Double_t APPT_ESumH;
    Double_t APPT_ESumS;
    Double_t APPT_TSum;

    TH1D*    hAPPT_Ener[15];
    TH1D*    hAPPT_Time[15];
    TH2D*    hAPPT_EvsT[15];

    TH1D*    hAPPT_TSum;
    TH1D*    hAPPT_ESumH;
    TH2D*    hAPPT_EHvsT;
    TH1D*    hAPPT_ESumS;
    TH2D*    hAPPT_ESvsT;

    TH2D*    hAPPT_EHvsES;
    TH2D*    hAPPT_EHvsES_NePi;

    Double_t OACut;

    Int_t    verbosity;
    Bool_t   excl_pi0;
    Bool_t   excl_pro;

protected:
    virtual Bool_t  Start();
    virtual void    ProcessEvent();
    virtual void	ProcessScalerRead();
    virtual Bool_t    Write();
			
public:
    PActive();
    virtual ~PActive();
    virtual Bool_t  Init();
    Bool_t InitVerbosity();
    Bool_t InitExclusivity();
    Bool_t InitOpeningAngle();
    Bool_t InitActiveChannel();
    Bool_t InitActiveScale();

};
#endif
