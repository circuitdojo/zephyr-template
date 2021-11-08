# Circuit Dojo Zephyr Template

## SDK Setup

1. Set up directory

   ```
   mkdir -p your-project-zephyr
   cd your-project-zephyr
   ```

2. Python virtual env:

   ```
   virtualenv -p python3 env
   ```

3. Source it:

   **For bash/sh**
   ```
   source ./env/bin/activate.sh
   ```

   **For fish**
   ```
   source ./env/bin/activate.fish
   ```

4. Install `west`

   ```
   pip3 install west
   ```

5. Pull the repository 

   ```
   west init -m <Git URL>
   ```

6. Fetch all other deps

   ```
   west update
   ```

7. Install zephyr dependencies

   ```
   pip3 install -r zephyr/scripts/requirements.txt
   ```

8. Install toolchain

   * For **Mac** run the following: (it does require you install `wget`. `brew` is an easy way to do so: `brew install wget`)

      ```
      cd ~
      wget "https://developer.arm.com/-/media/Files/downloads/gnu-rm/9-2019q4/gcc-arm-none-eabi-9-2019-q4-major-mac.tar.bz2"
      tar xvfj gcc-arm-none-eabi-9-2019-q4-major-mac.tar.bz2
      rm gcc-arm-none-eabi-9-2019-q4-major-mac.tar.bz2
      ```

      **Note** for Catalina users you will get an error when running these utilities for the first time. You must allow them to be executed in your Security preferences.

      ![Error running ARM Toolchain](img/sdk-setup-mac/cannot-be-opened.jpeg)


   * For **Windows** you can download and install the toolchain with [this direct link.](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads/9-2019-q4-major)

We're done with the setup. Now for the real fun..

## Building

```
export ZEPHYR_TOOLCHAIN_VARIANT=gnuarmemb
export GNUARMEMB_TOOLCHAIN_PATH=/path/to/toolchain/gcc-arm-none-eabi-9-2019-q4-major

west build -b circuitdojo_feather_nrf9160_ns
```

**Note:** `ZEPHYR_TOOLCHAIN_VARIANT` and `GNUARMEMB_TOOLCHAIN_PATH` can be set by default in the `CMakeLists.txt` file for this project.

## Viewing console output

The best way to view console output is to use the Nordic's LTE Link Monitor (via [nRF Connect for Desktop](https://www.nordicsemi.com/Products/Development-tools/nrf-connect-for-desktop)) or your favorite terminal. 

For exampe, here's how to load it in a Mac OS terminal:

```
sudo cu -l /dev/tty.SLAB_USBtoUART -s 115200
```
