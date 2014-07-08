set output "FlatnessContributionsRatio.pdf"
set term pdf
col = 5
plot \
"/tmp/VTKGitAnalysis.txt" using 1:col with lines title "VTK", \
"/tmp/ITKGitAnalysis.txt" using 1:col with lines title "ITK", \
"/tmp/LinuxKernelGitAnalysis.txt" using 1:col with lines title "Linux Kernel", \
"/tmp/FirefoxGitAnalysis.txt" using 1:col with lines title "Firefox"
