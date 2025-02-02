// SPDX-License-Identifier: GPL-2.0
#ifndef MEMCTRL_H
#define MEMCTRL_H
/**
 * \file
 *
 * Provides information about the memory controller status
 * (running DRAM configuration, ECC, ...) and other
 * platform-specific data
 *
 *//*
 * Copyright (C) 2004-2023 Sam Demeulemeester.
 */

typedef struct __attribute__((packed)) imc_infos {
    char        *type;
    uint16_t    family;
    uint16_t    freq;
    uint16_t    width;
    uint16_t    tCL;
    uint8_t     tCL_dec;
    uint16_t    tRCD;
    uint16_t    tRP;
    uint16_t    tRAS;
} imc_info_t;

typedef enum {
    ECC_ERR_NONE,
    ECC_ERR_CORRECTED,
    ECC_ERR_UNCORRECTED
} ecc_error_type_t;

typedef struct __attribute__((packed)) ecc_status {
    bool                ecc_enabled;
    ecc_error_type_t    err_type;
    uint64_t            err_adr;
    uint32_t            err_col;
    uint32_t            err_row;
    uint32_t            err_rank;
    uint32_t            err_bank;
} ecc_info_t;

/**
 * Current DRAM configuration of the Integrated Memory Controller
 */

extern imc_info_t imc;

/**
 * Current ECC Status of the Integrated Memory Controller
 */

extern ecc_info_t ecc_status;

void memctrl_init(void);

#endif // MEMCTRL_H
