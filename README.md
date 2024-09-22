# X68000 Z ジョイカード互換スケッチ（Xboxコントローラー用）

## 概要
Arduino+USB Host ShieldでXboxコントローラをX68000 Z ジョイカード互換コントローラとして使えるようにするスケッチです。  

## 準備
Arduino+USB Host Shieldを組み合わせた回路が必要です。  
また、スケッチを書き込むために[Arduino IDE](https://www.arduino.cc/en/software)と[USB_Host_Shield_2.0ライブラリ](https://github.com/felis/USB_Host_Shield_2.0)、[Arduino Joystick Library Version 2.1.1](https://github.com/MHeironimus/ArduinoJoystickLibrary)が必要です。  

## 使い方
Arduino+USB Host Shieldを組み合わせた回路にスケッチを書き込みます。  
X68000 ZとArduino+USB Host Shieldを繋ぎ、Xboxコントローラーを接続をします。  

XboxコントローラーがX68000 Z ジョイカード互換コントローラとして使えるようになります。  

## キー設定
左スティック…移動  
方向パッド…移動  

Aボタン…Bボタン  
Bボタン…Aボタン  
Xボタン…Bボタン連射ON/OFF  
Yボタン…Aボタン連射ON/OFF  

ビューボタン…SELECT  
メニューボタン…START  
Lボタン…Lボタン  
Rボタン…Rボタン  

## リリースノート

### 0.0.1

初版
