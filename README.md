# Vehicle-Control-System

# In the State where the Engine is OFF we can either Turn ON the Engine or QUIT the System
# In the State Engine is ON we can use the Air Conditioner or Engine Cooler or the Accelerator to alter the temperature or the speed of the vehicle Depending on their current temperature and The traffic light to control the speed 

# State Diagram for the System
![2023-03-01](https://user-images.githubusercontent.com/59807200/222007727-f79d92ca-f131-4f25-8d5e-d81d76e9df7b.png)


```mermaid
stateDiagram-v2
    [*] --> First
    state First {
        [*] --> second
        second --> [*]
    }
```
