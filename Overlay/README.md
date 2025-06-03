# 📈 Overlaying histograms

This folder contains a ROOT macro that overlays histograms from different physics processes on the same canvas. It’s a simple example to help you start working with ROOT visualizations.

### ▶️ How to run
Launch ROOT and run the macro from the prompt:
```
root -l
[] .x overlay.C
```
Make sure the input ROOT files are present in:  
`../Analysis_Codes/hst_files/`

### ⚙️ Important ROOT classes and where to find them

Here are the key ROOT classes used in `overlay.C`, with links to their official documentation:
| Class Name | Documentation Link | Purpose                                         |
|------------|--------------------|------------------------------------------------|
| TFile      | [TFile class documentation](https://root.cern/doc/master/classTFile.html) | To open `.root` files.                           |
| TH1F       | [TH1F class documentation](https://root.cern/doc/master/classTH1F.html)  | Handling 1D histograms.                                   |
| TCanvas    | [TCanvas class documentation](https://root.cern/doc/master/classTCanvas.html) | Canvas to draw on.                               |
| TLegend    | [TLegend class documentation](https://root.cern/doc/master/classTLegend.html) | To add plot legends.                             |
| TString    | [TString class documentation](https://root.cern/doc/master/classTString.html) | Flexible string handling.                        |
| TAxis      | [TAxis class documentation](https://root.cern/doc/master/classTAxis.html) | Controls histogram axes (titles, labels, ranges). |


### 📌 Tip
Want to try different plots?
🔍 Use ROOT’s built-in file explorer:
```
root hst*.root
[] new TBrowser;
```