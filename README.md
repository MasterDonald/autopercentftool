# Auto %f Tool by MasterDonald

## Disclaimers!!
* This tool was heavily inspired by moyashi's mugen auto %f tool, do check his [channel](https://www.youtube.com/channel/UC0JAnPhBzMqQ_Y_0-EthIhg) out.
* It only provides output on the classic %n [formula](https://mugen-cheap.fandom.com/wiki/Three_Writing_Formulas_for_Ordinary_%25n), which is `"%*d%n%d"`.
* **It does NOT manipulate the handler's pointer by itself.**
* **It does NOT include the last %f pos X state controller.**
* You have to compile the code yourself.

## Overview
Auto %f tool is a simple program written in C++ which aims to help the user develop %f codes way faster.
It was made due to moyashi's mugen application being Japanese (requiring LocaleEmulator) and written in batch.

## Usage
Once you've compiled the code correctly, you'll be prompted with two input fields.
1) The hexadecimal address where you are going to write into winMUGEN's memory.
2) The hexadecimal bytes of your shellcode.

The tool then automatically converts all hexadecimal into decimal, providing you a textfile named `output.txt` with all the %n for you to copy and paste into your character.
