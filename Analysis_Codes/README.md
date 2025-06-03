# 🚀 Running the Analysis with `ana.C`

This part of the repository contains a MakeSelector-based analysis setup to process NanoAOD files. 

### 📁 Directory Structure
```
├── ana.C        → Driver script that runs the compiled library.
├── nanoAna.C    → The main script containing the event loop.
├── nanoAna.h    → MakeSelector class definition. Variables and branches are declared here.
├── cleanup.py   → Python script used to clean the directory.
├── inputs       → Keep the input nanoAOD files here.
├── hst_files    → Output histograms (.root files).
└── sum_files    → Additional text files containing summary.
```

### ▶️ How to run

1. 🛠️ **Compile the MakeSelector class**
   
   The file `nanoAna.C` is a ROOT MakeSelector-based class that contains the event loop. Before running any analysis, you must compile it using ROOT's interpreter. At the ROOT prompt, do the folllowing.
   ```root
   .L nanoAna.C+
   ```
   The `+` tells ROOT to compile the file with ACLiC and produce shared object files (`nanoAna_C.so`, etc.) that speed up execution and enable proper class handling.

2. 🚀 **Run the driver script**
   Once the class is compiled, you can launch the analysis using the provided driver script as follows.
   ```
   .x ana.C(0)
   ```
   This will execute the `ana` macro, which internally uses `TChain` to load NanoAOD input files and applies the `nanoAna` selector to process them. You can modify `ana.C` to change input/output file paths. After execution, output histograms will typically be saved in the `hst_files/` directory as `.root` files.

For questions or help, feel free to contact me.
 