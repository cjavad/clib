Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip
{
    param([string]$zipfile, [string]$outpath)

    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
}

function Download
{
    param([string]$url, [string]$output)
    (New-Object System.Net.WebClient).DownloadFile($url, $output)
}

$path = "${pwd}\"
$link = "https://github.com/weidai11/cryptopp/archive/CRYPTOPP_5_6_5.zip"
# create dir
mkdir "${path}include"
Download $link ".\crypto\crypto.zip"
Unzip "${path}crypto.zip" "${path}include"

$in = "cryptopp-CRYPTOPP_5_6_5"

Move-Item "${path}include\${in}\*" "${path}include"
# delete files an dirs
rmdir "${path}include\${in}"
del "${path}crypto.zip"
# cd to the include dir
cd "${path}include"
# convert all to header files
Dir *.cpp | rename-item -newname { [io.path]::ChangeExtension($_.name, "hpp") }