/*++
 *
 * Copyright (c) 2022  Attivo Networks
 *  
 *  Module Name: Dynamic library
 *    
 *  Author: Mayur Navadia
 *
 *  Abstract: Dynamic library.
 *  User mode
 *
 */
#ifndef __AAL_LINUX_OPENSOURCE_H
#define __AAL_LINUX_OPENSOURCE_H
#include <stdint.h>
#include <linux/types.h>
#include <stdbool.h>

typedef int an_callback(void*, void*, void*, void*);

void* an_get_msg_pkt_hdr(void*);
int an_get_payload(void*, unsigned char **data);
int an_set_verdict(void* qh, unsigned int id, unsigned int verdict, unsigned int data_len, const unsigned char* buf);
void* an_open();
int an_bind_pf(void* , unsigned short pf);
int an_unbind_pf(void*, unsigned short pf);
int an_fd_fund(void*);
void* an_create_queue(void*, unsigned short num, an_callback* cb, void* data);
int an_destroy_queue(void*);
int an_handle_packet(void*, char* buf, int len);
int an_set_mode(void*, unsigned char mode, unsigned int len);
int an_close_func(void*);

#endif
