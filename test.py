import sys
import os

files = list(filter(lambda file: ".mmc" in file, os.listdir("data")))

os.chdir("data")

if not os.path.exists("build"):
    os.mkdir("build")

if not os.path.exists("run"):
    os.mkdir("run")

compile_cmd = "..\\Debug\\PiedPiper.exe {} > build/{}_build.txt"
build_cmd   = "build_jasmin {}.j"
run_cmd     = "java {0} > run/{0}_run.txt"

for file in files:
    filename = file.split(".")[0]
    print(filename)

    os.system(compile_cmd.format(file, filename))

    if "error" not in filename:
        os.system(build_cmd.format(filename))
        os.system(run_cmd.format(filename))
