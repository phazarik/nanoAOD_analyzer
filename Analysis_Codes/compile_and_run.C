#include <TSystem.h>
#include <TROOT.h>
#include <TStopwatch.h>
#include <iostream>
using namespace std;

string fmt(double t) {
    int h = t / 3600;
    int m = ((int)t % 3600) / 60;
    int s = (int)t % 60;
    char buf[16];
    sprintf(buf, "%02d:%02d:%02d", h, m, s);
    return string(buf);
}

void compile_and_run(int sample = 0) {

    TString scriptPath = gSystem->DirName(__FILE__);

    // 1. Explicitly load necessary ROOT libraries before compiling
    cout << "\n[DRIVER SCRIPT]\033[1;33m Loading libraries...\033[0m" << endl;
    gSystem->Load("libTree");
    gSystem->Load("libTreePlayer");
    gSystem->Load("libPhysics");
    gSystem->Load("libHist");

    // 2. Setup DNN libraries with RPATH
    TString onnxdir = scriptPath + "/../onnxruntime-linux-x64-1.24.4";
    gSystem->AddIncludePath(Form("-I%s/include", onnxdir.Data()));
    
    // NOTE: -Wl,-rpath bakes the library directory directly into the compiled object
    // so the OS knows exactly where to look for libonnxruntime.so.1 at runtime.
    gSystem->AddLinkedLibs(Form("-Wl,-rpath,%s/lib -L%s/lib -lonnxruntime", onnxdir.Data(), onnxdir.Data()));
    if (gSystem->Load(onnxdir + "/lib/libonnxruntime.so") < 0) {
        cerr << "[DRIVER SCRIPT]\033[31m ERROR: Could not find libonnxruntime.so!\033[0m" << endl;
        return;
    }

    // 3. Compile the source code:
    TStopwatch time_compile;
    time_compile.Start();
    cout << "[DRIVER SCRIPT]\033[1;33m Compiling nanoAna.C...\033[0m" << endl;
    if (gSystem->CompileMacro("nanoAna.C", "kO") == 0) {
        cerr << "[DRIVER SCRIPT] \033[31mERROR: Compilation of nanoAna.C failed!\033[0m" << endl;
        return;
    }
    time_compile.Stop();
    cout << "[DRIVER SCRIPT]\033[1;34m Compilation time: " << fmt(time_compile.RealTime()) << "\033[0m" << endl;

    // 4. Run ana.C:
    TStopwatch time_run;
    time_run.Start();
    cout << "[DRIVER SCRIPT]\033[1;33m Running ana(" << sample << ")...\033[0m" << endl;
    gROOT->ProcessLine(Form(".x ana.C(%d)", sample));
    time_run.Stop();
    cout << "[DRIVER SCRIPT]\033[1;34m Runtime: " << fmt(time_run.RealTime()) << "\033[0m\n" << endl;
}
