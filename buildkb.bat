docker run -e keymap=td2 -e keyboard=atomic --rm -v c:/Users/td/dev/qmk_firmware:/qmk:rw edasque/qmk_firmware
teensy_loader_cli.exe -w -v -mmcu=at90usb1286 atomic_td2.hex
