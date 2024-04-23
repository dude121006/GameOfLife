import os
import pyperclip
import sys
import pathlib

src = "D:\\Krishanth\\Dev\\VS\\sfml\\ConsoleApplication1"
src = os.getcwd()

desiredTypes = ["cpp", "h", "hpp", "json"]

# Reads the file and returns its content
def ReadContent(path):
    with open(path, 'r') as file:
        return file.read()

# returns the paths of all files in the given directory path
def GetFiles(path):
    filePaths = []

    for file in os.listdir(src):
        if os.path.isfile(os.path.join(src, file)):
            extension = pathlib.Path(file).suffix[1:]
            if extension in desiredTypes:
                filePaths.append(os.path.join(src, file))
    return filePaths

# Takes in a list of file paths, reads the content of all the files, returns it as a single string    
def GetContent(filePaths):
    cont = ""
    for filePath in filePaths:
        
        tempCont = ReadContent(filePath)
        fileName = pathlib.Path(filePath).name

        cont = cont + f"contents of {fileName} file: " + "\n\n"
        cont += tempCont
        cont = cont + "\n\n" + "-" * 35 + "\n" *2

    return cont


if __name__ == "__main__":
    
    files = GetFiles(src)
    
    # checks for extra arguments while running the file
    if len(sys.argv) > 1:
        #overrides the files list with the entered files
        files = sys.argv[1:]
        files = [os.path.join(src, x) for x in files]

    Content = GetContent(files)
    #copies the content to clipboard
    pyperclip.copy(Content)