void ProtonEffActive(TString sFile, Double_t dMaCutLo=900, Double_t dMaCutHi=980, const Int_t iRebinEk=2, const Int_t iRebinTh=2){
  TFile f1(sFile,"READ");

  gROOT->cd();
  TH3D *hEkThMa = (TH3D*)f1.Get("hEkThMa");
  TH3D *hEkThMa_OA = (TH3D*)f1.Get("hEkThMa_OA");
  TH3D *hEkThMa_Ch = (TH3D*)f1.Get("hEkThMa_Ch");

  Int_t nBins = 12/iRebinTh;

  TH1D *hEk[12/iRebinTh];
  TH1D *hEk_OA[12/iRebinTh];
  TH1D *hEk_Ch[12/iRebinTh];
  TH1D *hEf_OA[12/iRebinTh];
  TH1D *hEf_Ch[12/iRebinTh];

  Int_t iMaCutLo = hEkThMa->GetZaxis()->FindBin(dMaCutLo);
  Int_t iMaCutHi = hEkThMa->GetZaxis()->FindBin(dMaCutHi);

  Int_t nWide = TMath::CeilNint(TMath::Sqrt(nBins));
  Int_t nHigh = TMath::FloorNint(TMath::Sqrt(nBins));

  TCanvas *cEk = new TCanvas("cEk","cEk");
  cEk->Divide(nWide,nHigh);
  TCanvas *cEk_OA = new TCanvas("cEk_OA","cEk_OA");
  cEk_OA->Divide(nWide,nHigh);
  TCanvas *cEk_Ch = new TCanvas("cEk_Ch","cEk_Ch");
  cEk_Ch->Divide(nWide,nHigh);
  TCanvas *cEf_OA = new TCanvas("cEf_OA","cEf_OA");
  cEf_OA->Divide(nWide,nHigh);
  TCanvas *cEf_Ch = new TCanvas("cEf_Ch","cEf_Ch");
  cEf_Ch->Divide(nWide,nHigh);

  for(Int_t i=0; i<nBins; i++){
    cEk->cd(i+1);
    hEk[i] = (TH1D*)hEkThMa->ProjectionX(Form("hEk_%d",i),(i*iRebinTh)+1,(i+1)*iRebinTh,iMaCutLo,iMaCutHi);
    hEk[i]->SetTitle(Form("Expected recoil (%d - %d deg)",(i*iRebinTh)*5,(i+1)*iRebinTh*5));
    hEk[i]->Rebin(iRebinEk);
    hEk[i]->DrawClone();

    cEk_OA->cd(i+1);
    hEk_OA[i] = (TH1D*)hEkThMa_OA->ProjectionX(Form("hEk_OA_%d",i),(i*iRebinTh)+1,(i+1)*iRebinTh,iMaCutLo,iMaCutHi);
    hEk_OA[i]->SetTitle(Form("Detected recoil (%d - %d deg)",(i*iRebinTh)*5,(i+1)*iRebinTh*5));
    hEk_OA[i]->Rebin(iRebinEk);
    hEk_OA[i]->DrawClone();

    cEk_Ch->cd(i+1);
    hEk_Ch[i] = (TH1D*)hEkThMa_Ch->ProjectionX(Form("hEk_Ch_%d",i),(i*iRebinTh)+1,(i+1)*iRebinTh,iMaCutLo,iMaCutHi);
    hEk_Ch[i]->SetTitle(Form("Detected charge (%d - %d deg)",(i*iRebinTh)*5,(i+1)*iRebinTh*5));
    hEk_Ch[i]->Rebin(iRebinEk);
    hEk_Ch[i]->DrawClone();

    cEf_OA->cd(i+1);
    hEf_OA[i] = (TH1D*)hEk_OA[i]->Clone(Form("hEf_OA_%d",i));
    hEf_OA[i]->Divide(hEk[i]);
    hEf_OA[i]->DrawClone();

    cEf_Ch->cd(i+1);
    hEf_Ch[i] = (TH1D*)hEk_Ch[i]->Clone(Form("hEf_Ch_%d",i));
    hEf_Ch[i]->Divide(hEk[i]);
    hEf_Ch[i]->DrawClone();
  }
}
