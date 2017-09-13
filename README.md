# Color sorter LPC1114fn28 firmware

This is the code that runs my color sorting machine on a LPC1114FN28. It was written as part of the final project for the first year of the University of Applied Sciences Utrecht.

The codebase uses BMPTK (Bare Metal Programming Tool Kit), built by Wouter van Ooijen. This library can be found [here](http://www.voti.nl/bmptk/n_index.html).

## Usage
After downloading and extracting the BMPTK zip file, edit the url into the Makefile. You will also need to connect a LPC1114FN28 using a USB cable.

Then run

```
make build
make run
```

## Pictures & Videos

<video src="Readme/example.mp4" width="360" height="640" controls preload></video>
