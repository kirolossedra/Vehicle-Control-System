# Vehicle-Control-System

# In the State where the Engine is OFF we can either Turn ON the Engine or QUIT the System
# In the State Engine is ON we can use the Air Conditioner or Engine Cooler or the Accelerator to alter the temperature or the speed of the vehicle Depending on their current temperature and The traffic light to control the speed 

# State Diagram for the System
![2023-03-01](https://user-images.githubusercontent.com/59807200/222007727-f79d92ca-f131-4f25-8d5e-d81d76e9df7b.png)



```mermaid
classDiagram
class SimpleRemoteControl {
  - slot: Command
  + SimpleRemoteControl()
  + setCommand(command: Command): void
  + buttonWasPressed(): void
}

class Command {
  + execute(): void
}

class Light {
  + on(): void
  + off(): void
}

class LightOnCommand {
  - light: Light
  + LightOnCommand(light: Light)
  + execute(): void
}

class LightOffCommand {
  - light: Light
  + LightOffCommand(light: Light)
  + execute(): void
}

class Stereo {
  + on(): void
  + off(): void
  + setCD(): void
  + setDVD(): void
  + setRadio(): void
  + setVolume(volume: int): void
}

class StereoOffCommand {
  - stereo: Stereo
  + StereoOffCommand(stereo: Stereo)
  + execute(): void
}

class StereoOnWithCDCommand {
  - stereo: Stereo
  + StereoOnWithCDCommand(stereo: Stereo)
  + execute(): void
}

SimpleRemoteControl -> Command: uses
Light -> Command: implements
LightOnCommand -> Command: implements
LightOffCommand -> Command: implements
LightOnCommand -> Light: uses
LightOffCommand -> Light: uses
Stereo -> Command: implements
StereoOffCommand -> Command: implements
StereoOnWithCDCommand -> Command: implements
StereoOffCommand -> Stereo: uses
StereoOnWithCDCommand -> Stereo: uses
SimpleRemoteControl ..> LightOnCommand: slot
SimpleRemoteControl ..> LightOffCommand: slot
SimpleRemoteControl ..> StereoOnWithCDCommand: slot
SimpleRemoteControl ..> StereoOffCommand: slot
```



