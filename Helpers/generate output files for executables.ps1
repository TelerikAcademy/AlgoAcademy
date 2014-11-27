for($i = 1; $i -lt 20; $i++) {
	$fileName = [string]::Format("test.{0:000}.in.txt", $i)
	$fileNameOut = [string]::Format("test.{0:000}.out.txt", $i)
	
	$output = cmd /c program.exe `>$fileNameOut `<$fileName
		
	Write-Output $fileName
}
