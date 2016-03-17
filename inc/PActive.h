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

    TH1*	NePiTime;
    TH1*	NePiTCut;
    GH3*	NePiEkThMa;
    GH3*	NePiEkATMa;

    TH1*	NePiOATime;
    TH1*	NePiOATCut;
    GH3*	NePiOAEkThMa;
    GH3*	NePiOAEkATMa;

    GH1*	IM;
    GH1*	MM;

    Int_t APPT_ADC[16];
    Int_t APPT_TDC[16];

    Double_t APPT_Ener[16];
    Double_t APPT_Time[16];
    Double_t APPT_ESum;

    TH1D*   hAPPT_Ener[16];
    TH1D*   hAPPT_Time[16];
    TH2D*   hAPPT_EvsT[16];
    TH1D*   hAPPT_ESum;
    TH2D*   hAPPT_TSum;

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

};
#endif
