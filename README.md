# 📊 Producing and Overlaying Histograms

Welcome! This repository is a quick-start guide for undergraduates stepping into experimental high-energy physics (HEP) for the first time. You'll learn how to analyze proton-proton collision events, generate histograms, and overlay them to compare the different physics processes.


![ROOT](https://img.shields.io/badge/ROOT-6.26.10-00ADD8?logo=root&logoColor=white&style=for-the-badge)  ![Conda](https://img.shields.io/badge/Conda-24.9.1-44A833?logo=anaconda&logoColor=white&style=for-the-badge)   ![Python](https://img.shields.io/badge/Python-3.10.9-3776AB?logo=python&logoColor=white&style=for-the-badge)


### 🚀 New to This? Start Here!

No worries - I've got you covered. This repository is self-contained. Follow the steps below to ease into the workflow.
- Begin with the `Overlay` example.
- I've included a couple of example `.root` files that contain histograms. These are kept as follows.
   ```
  └── Analysis_Codes
    └──  hst_files
        ├── hst_DYM50.root
        └── hst_ttjets.root
     ```
        
- Using these input files, try exploring the different features of ROOT classes by playing around with [overlay.C](Overlay/overlay.C). More information on how to run this can be found [here](Overlay/README.md).
- Once you are comfortable with overlaying histograms, you can produce your own histograms using the analysis codes. The detailed instructions for this can be found [here](Analysis_Codes/README.md). I have included a test file containing ZZto4L events that correspond to data taken in 2022 in the CMS detector.
  ```
  └──  Analysis_Codes
        └── inputs
        └── testfile_Run3Summer22.root
     ```

### 📦 Want More Samples?
Contact me if you'd like more example files from different physics processes, I'm happy to help!

[![Discord](https://img.shields.io/badge/Discord-phazarik-5865F2?logo=discord&logoColor=white&style=for-the-badge)](#)  
[![Email](https://img.shields.io/badge/Email-prachurjya.hazarika%40students.iiserpune.ac.in-D14836?logo=gmail&logoColor=white&style=for-the-badge)](mailto:prachurjya.hazarika@students.iiserpune.ac.in)