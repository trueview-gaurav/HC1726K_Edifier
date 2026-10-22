# list of boards that use i2c-1 for sensor
BOARD_I2C_1 := EM1 TB001_DVP TB003
BOARD_I2C_1 += MB001 MB006 MB008 MB013
BOARD_I2C_1 += BOS_MA90205_V1.0.0
BOARD_I2C_1 += MKE_MA00102_V1
BOARD_I2C_1 += MA10001

# list of boards that use i2c-0 for sensor
# unlisted boards will still use i2c-0 by default
BOARD_I2C_0 := TB006 TB007 TB008 MA10021
BOARD_I2C_0 += MB021 MB021_V2 MB022 MB023 MB033
BOARD_I2C_0 += MKE_MA80030
