/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *   Mupen64plus-rsp-hle - main.h                                          *
 *   Mupen64Plus homepage: http://code.google.com/p/mupen64plus/           *
 *   Copyright (C) 2014 Bobby Smiles                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

#include "alist.h"

/* rsp hle internal state */
struct hle_t
{
    unsigned char* dram;
    unsigned char* dmem;
    unsigned char* imem;

    unsigned int* mi_intr;

    unsigned int* sp_mem_addr;
    unsigned int* sp_dram_addr;
    unsigned int* sp_rd_length;
    unsigned int* sp_wr_length;
    unsigned int* sp_status;
    unsigned int* sp_dma_full;
    unsigned int* sp_dma_busy;
    unsigned int* sp_pc;
    unsigned int* sp_semaphore;

    unsigned int* dpc_start;
    unsigned int* dpc_end;
    unsigned int* dpc_current;
    unsigned int* dpc_status;
    unsigned int* dpc_clock;
    unsigned int* dpc_bufbusy;
    unsigned int* dpc_pipebusy;
    unsigned int* dpc_tmem;

    void (*CheckInterrupts)(void);
    void (*ProcessDlistList)(void);
    void (*ProcessAlistList)(void);
    void (*ProcessRdpList)(void);
    void (*ShowCFB)(void);

    /* alist.c */
    uint8_t alist_buffer[0x1000];

    /* alist_audio.c */
    struct alist_audio_t alist_audio;

    /* alist_naudio.c */
    struct alist_naudio_t alist_naudio;

    /* alist_nead.c */
    struct alist_nead_t alist_nead;

    /* mp3.c */
    uint8_t mp3_buffer[0x1000];
    uint32_t mp3_inPtr;
    uint32_t mp3_outPtr;
    uint32_t mp3_t6;
    uint32_t mp3_t5;
    uint32_t mp3_t4;
};

void hle_execute(struct hle_t* hle);

#endif

