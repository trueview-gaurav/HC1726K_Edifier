#ifndef CHIP_PACKAGE_H_
#define CHIP_PACKAGE_H_

enum chip_package_type {
	TFBGA193 = 0,
	LQFP128,
	TFBGA225,
	QFN100,
	MAX_PACKAGE_TYPE,
};

struct chip_package {
	enum chip_package_type type;
};

static struct chip_package chip_packages[] = {
	{ TFBGA193 },
	{ TFBGA193 },
	{ TFBGA193 },
	{ LQFP128 },
	{ LQFP128 },
	{ TFBGA225 },
	{ LQFP128 },
	{ TFBGA193 },
	{ QFN100 },
	{ QFN100 }
};

#endif /* CHIP_PACKAGE_H_ */
