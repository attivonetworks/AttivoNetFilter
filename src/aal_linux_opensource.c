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

#include "aal_linux_nfq_opensource.h"
#include <sys/types.h>
#include "libnetfilter_include/libnetfilter_queue.h"
#include <dlfcn.h>


void* an_get_msg_pkt_hdr(void* nfad)
{
    return nfq_get_msg_packet_hdr((struct nfq_data *)nfad);    
}

int an_get_payload(void* nfad, unsigned char **data)
{
    return nfq_get_payload(nfad, data);
}

int an_set_verdict(void* qh, unsigned int id, unsigned int verdict, unsigned int data_len, const unsigned char* buf)
{
    return nfq_set_verdict(qh, id, verdict, data_len, buf);
}

void* an_open()
{
    return nfq_open();
}

int an_bind_pf(void* handle, unsigned short pf)
{
    return nfq_bind_pf(handle, pf);
}

int an_unbind_pf(void* handle, unsigned short pf)
{
    return nfq_unbind_pf(handle, pf);   
}

void* an_create_queue(void* handle, unsigned short num, an_callback* cb, void* data)
{
    return nfq_create_queue(handle, num, (nfq_callback*)cb, data);
}

int an_destroy_queue(void* handle)
{
    return nfq_destroy_queue(handle);     
}

int an_handle_packet(void* handle, char* buf, int len)
{
    return nfq_handle_packet(handle, buf, len);
}

int an_set_mode(void* handle, unsigned char mode, unsigned int len)
{
    return nfq_set_mode(handle, mode, len);
}

int an_close(void* handle)
{
    return nfq_close(handle);
}

int an_fd_fund(void* handle)
{
    return nfq_fd(handle);
}






