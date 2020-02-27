#define MyAppName "sfizz-lv2"
#define MyAppVersion "0.3.0"
#define MyAppPublisher "sfizz Team"
#define MyAppURL "https://sfztools.github.io/sfizz/"

[Setup]
AlwaysShowDirOnReadyPage=yes
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppId={{55FB694B-774A-4BB8-B08C-F6C015821ECC}
AppName={#MyAppName}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
;AppVerName={#MyAppName} {#MyAppVersion}
AppVersion={#MyAppVersion}
ArchitecturesAllowed=x86 x64
ArchitecturesInstallIn64BitMode=x64
Compression=lzma
SolidCompression=yes
DefaultDirName={commoncf}\LV2
DefaultGroupName={#MyAppPublisher}
DisableDirPage=yes
LicenseFile=CMakeBuild\sfizz.lv2\LICENSE.md
OutputBaseFilename={#MyAppName}-setup
UninstallFilesDir={commonpf}\{#MyAppName}
WizardImageFile="C:\Program Files (x86)\Inno Setup 6\WizModernImage-IS.bmp"
WizardSmallImageFile="C:\Program Files (x86)\Inno Setup 6\WizModernSmallImage-IS.bmp"

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "CMakeBuild\sfizz.lv2\sfizz.dll";    DestDir: {commoncf}\LV2\sfizz.lv2; Flags: ignoreversion
Source: "CMakeBuild\sfizz.lv2\manifest.ttl"; DestDir: {commoncf}\LV2\sfizz.lv2
Source: "CMakeBuild\sfizz.lv2\sfizz.ttl";    DestDir: {commoncf}\LV2\sfizz.lv2
Source: "CMakeBuild\sfizz.lv2\lgpl-3.0.txt"; DestDir: {commonpf}\{#MyAppName}
Source: "CMakeBuild\sfizz.lv2\LICENSE.md";   DestDir: {commonpf}\{#MyAppName}
;Source: "setup\vc_redist.x64.exe"; DestDir: {tmp}; Flags: deleteafterinstall
; NOTE: Don't use "Flags: ignoreversion" on any shared system files

;[Run]
;Filename: {tmp}\vc_redist.x64.exe; \
    Parameters: "/install /passive /norestart"; \
    StatusMsg: "Installing Microsoft Visual C++ 2015-2019 Redistributable (x64)..."
;Filename: {app}\{#MyAppExeName}; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
