/*******************************************************************************
* File Name: cymetadata.c
* 
* PSoC Creator  4.3
*
* Description:
* This file defines all extra memory spaces that need to be included.
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2019 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include "stdint.h"


#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_CONFIG_ECC_SECTION
#define CY_CONFIG_ECC_SECTION __attribute__ ((__section__(".cyconfigecc"), used))
#endif
CY_CONFIG_ECC_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cyconfigecc"
#else
#error "Unsupported toolchain"
#endif
const uint8_t cy_meta_configecc[] = {
    0x02u, 0x45u, 0x00u, 0x40u, 0x04u, 0x4Fu, 0x00u, 0x40u,
    0x01u, 0x52u, 0x00u, 0x40u, 0x01u, 0x05u, 0x01u, 0x40u,
    0x20u, 0x0Au, 0x01u, 0x40u, 0x0Bu, 0x0Bu, 0x01u, 0x40u,
    0x04u, 0x0Cu, 0x01u, 0x40u, 0x01u, 0x0Du, 0x01u, 0x40u,
    0x01u, 0x17u, 0x01u, 0x40u, 0x01u, 0x19u, 0x01u, 0x40u,
    0x06u, 0x42u, 0x01u, 0x40u, 0x02u, 0x43u, 0x01u, 0x40u,
    0x01u, 0x48u, 0x01u, 0x40u, 0x05u, 0x4Cu, 0x01u, 0x40u,
    0x02u, 0x50u, 0x01u, 0x40u, 0x1Cu, 0x01u, 0x1Du, 0x01u,
    0x01u, 0x10u, 0x0Au, 0x4Bu, 0x0Du, 0x20u, 0x16u, 0x4Bu,
    0x09u, 0x80u, 0xEAu, 0x08u, 0x40u, 0x05u, 0x49u, 0xFFu,
    0x4Au, 0xFFu, 0x4Bu, 0xFFu, 0x4Cu, 0x02u, 0x4Du, 0x0Cu,
    0x4Eu, 0xF8u, 0x52u, 0x01u, 0x5Au, 0x0Cu, 0x5Bu, 0x04u,
    0x5Fu, 0x01u, 0x62u, 0x48u, 0x63u, 0xA1u, 0x68u, 0xF0u,
    0x6Au, 0xF0u, 0x6Cu, 0xF0u, 0x6Eu, 0xF0u, 0xC0u, 0x04u,
    0xC9u, 0xFFu, 0xCAu, 0xFFu, 0xCBu, 0xFFu, 0xCCu, 0x03u,
    0xCDu, 0x0Cu, 0xCEu, 0xF4u, 0xDAu, 0x0Cu, 0xDFu, 0x01u,
    0xE2u, 0x48u, 0xE3u, 0xA1u, 0xE8u, 0xF0u, 0xEAu, 0xF0u,
    0xECu, 0xF0u, 0xEEu, 0xF0u, 0x47u, 0x02u, 0x48u, 0x01u,
    0x68u, 0x01u, 0x69u, 0x40u, 0x6Bu, 0x02u, 0x79u, 0x40u,
    0x7Du, 0x40u, 0xAFu, 0x40u, 0xD0u, 0x80u, 0xD2u, 0x08u,
    0xDEu, 0x18u, 0x38u, 0x80u, 0x3Eu, 0x40u, 0x58u, 0x04u,
    0x5Fu, 0x01u, 0x1Fu, 0x40u, 0xE8u, 0x10u, 0xE8u, 0x10u,
    0x5Bu, 0x08u, 0x5Fu, 0x08u, 0x9Bu, 0x08u, 0xAFu, 0x08u,
    0xD6u, 0xC0u, 0xEAu, 0x10u, 0x18u, 0x10u, 0xC6u, 0x10u,
    0xB4u, 0x10u, 0x60u, 0x80u, 0x98u, 0x80u, 0xB4u, 0x80u,
    0xD8u, 0x02u, 0xE8u, 0x08u, 0x00u, 0x01u, 0x0Cu, 0x01u,
    0x00u, 0x8Bu, 0x8Bu, 0x00u, 0x80u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x7Fu, 0x7Fu, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x30u, 0x30u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_CUST_NVL_SECTION
#define CY_CUST_NVL_SECTION __attribute__ ((__section__(".cycustnvl"), used))
#endif
CY_CUST_NVL_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cycustnvl"
#else
#error "Unsupported toolchain"
#endif
const uint8_t cy_meta_custnvl[] = {
    0x00u, 0x00u, 0x40u, 0x05u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_WO_NVL_SECTION
#define CY_WO_NVL_SECTION __attribute__ ((__section__(".cywolatch"), used))
#endif
CY_WO_NVL_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cywolatch"
#else
#error "Unsupported toolchain"
#endif
const uint8_t cy_meta_wonvl[] = {
    0xBCu, 0x90u, 0xACu, 0xAFu
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_FLASH_PROT_SECTION
#define CY_FLASH_PROT_SECTION __attribute__ ((__section__(".cyflashprotect"), used))
#endif
CY_FLASH_PROT_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cyflashprotect"
#else
#error "Unsupported toolchain"
#endif
const uint8_t cy_meta_flashprotect[] = {
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
};

#if defined(__GNUC__) || defined(__ARMCC_VERSION)
#ifndef CY_META_SECTION
#define CY_META_SECTION __attribute__ ((__section__(".cymeta"), used))
#endif
CY_META_SECTION
#elif defined(__ICCARM__)
#pragma  location=".cymeta"
#else
#error "Unsupported toolchain"
#endif
const uint8_t cy_metadata[] = {
    0x00u, 0x01u, 0x2Eu, 0x16u, 0x10u, 0x69u, 0x00u, 0x01u,
    0x00u, 0x00u, 0x00u, 0x00u
};
