try:
   fh = open(input("Enter file name : "),mode=input("Enter mode in which you would like to open the file : "))
   print(fh.read())
   fh.write("This is my test file for exception handling!!")
except (UnicodeDecodeError):
   print ("Error: can\'t read the file")
except(FileNotFoundError):
    print ("Error: Check the filename and path")
except(IsADirectoryError):
    print("Error:Can't open the directory")
except(PermissionError):
    print("Error: Check permissions")
except:
    print("Error: An error occured")
finally:
    print("This is printed always")
