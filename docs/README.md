# Wokwi-Chip-Analog-Bargraph

## Description

Converts an Analog Signal to 10-bit Bargraph (default) or Binary.



![image](https://user-images.githubusercontent.com/63488701/217864528-8e30935e-854d-414c-a454-2f2c1e65ca89.png)

![image](https://user-images.githubusercontent.com/63488701/217718560-3af1f830-bfca-4017-93cd-d8195d0ea6fa.png)

## Pin names

| Name  | Description                                                |
| ----- | ---------------------------------------------------------- |
| A0    | Analog Input  0-5V converts to 0-1023 (10-bit digital)     |
| D0-D9 | Digital output bits 0-9, Bargraph (default) or Binary mode |

## Usage

To use this chip in your project, include it as a dependency in your `diagram.json` file:

```json
  "dependencies": {
    "chip-analog-bargraph": "github:Dlloydev/Wokwi-Chip-Analog-Bargraph@1.0.2"
  }
```

Then, add the chip to your circuit by adding a `chip-analog-bargraph` item to the `parts` section of `diagram.json`:

```json
  "parts": {
    ...,
    { "type": "chip-analog-bargraph", "id": "chip-analog-bargraph1" }
  },
```

The actual source code for the chip lives in [src/main.c](https://github.com/Dlloydev/Wokwi-Chip-Analog-Bargraph/blob/main/src/main.c), and the pins are described in [chip.json](https://github.com/Dlloydev/Wokwi-Chip-Analog-Bargraph/blob/main/chip.json).

## Example

[![Wokwi_badge](https://user-images.githubusercontent.com/63488701/212449119-a8510897-c860-4545-8c1a-794169547ba1.svg)](https://wokwi.com/projects/356158677675183105) Display an Analog Signal on a Bargraph Example

## License

This project is licensed under the MIT license. See the [LICENSE](https://github.com/Dlloydev/Wokwi-Chip-Analog-Bargraph/blob/main/LICENSE) file for more details.
