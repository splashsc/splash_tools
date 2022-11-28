int __fastcall httpd_conn_send_finish(int a1)
{
  int v2; // $a0
  int v3; // $v0
  int v4; // $s1
  void *v5; // $a0
  FILE *v6; // $a0
  void *v7; // $a0
  int v8; // $a0
  int v10; // $s2
  FILE *v11; // $a0

  if ( (*(_DWORD *)(a1 + 36) & 1) == 0 )
  {
    v10 = a1 + 196608;
    *(_DWORD *)(a1 + 205556) = a1;
    *(_BYTE *)(a1 + 210101) = 1;
    *(_DWORD *)(a1 + 205548) = jiffies_get() + 10;
    *(_DWORD *)(v10 + 8944) = httpd_keep_alive_timeout;
    v8 = a1 + 205540;
    goto LABEL_15;
  }
  v2 = *(_DWORD *)(a1 + 48);
  if ( v2 )
  {
    cJSON_Delete(v2);
    *(_DWORD *)(a1 + 48) = 0;
  }
  v3 = *(unsigned __int8 *)(a1 + 42);
  if ( v3 == 1 )
  {
    _mem_free(*(void **)(a1 + 205372));
    *(_DWORD *)(a1 + 205372) = 0;
  }
  else if ( v3 == 2 )
  {
    v11 = *(FILE **)(a1 + 205592);
    if ( v11 )
    {
      fclose(v11);
      *(_DWORD *)(a1 + 205592) = 0;
      *(_DWORD *)(a1 + 209692) = 0;
      v4 = a1 + 196608;
      httpd_release_caches();
      v5 = *(void **)(a1 + 205564);
      if ( !v5 )
        goto LABEL_8;
      goto LABEL_7;
    }
  }
  v4 = a1 + 196608;
  v5 = *(void **)(a1 + 205564);
  if ( v5 )
  {
LABEL_7:
    _mem_free(v5);
    *(_DWORD *)(v4 + 8956) = 0;
  }
LABEL_8:
  if ( *(_DWORD *)(a1 + 205540) )
    del_timer(a1 + 205540);
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_BYTE *)(a1 + 40) = 0;
  *(_BYTE *)(a1 + 41) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 205492) = 0;
  *(_DWORD *)(a1 + 205488) = 0;
  *(_DWORD *)(a1 + 205512) = 0;
  *(_DWORD *)(a1 + 205516) = 0;
  *(_DWORD *)(a1 + 205496) = 0;
  *(_DWORD *)(a1 + 205400) = 0;
  *(_DWORD *)(a1 + 205372) = 0;
  *(_BYTE *)(a1 + 42) = 0;
  *(_DWORD *)(a1 + 205388) = 0;
  *(_DWORD *)(a1 + 205376) = 0;
  *(_DWORD *)(a1 + 205380) = 0;
  *(_DWORD *)(a1 + 205384) = 0;
  *(_DWORD *)(a1 + 205368) = 0;
  *(_BYTE *)(a1 + 43) = 0;
  *(_DWORD *)(a1 + 205396) = 0;
  *(_DWORD *)(a1 + 205392) = 0;
  memset((void *)(a1 + 564), 0, 0x19000u);
  *(_DWORD *)(a1 + 205364) = 0;
  memset((void *)(a1 + 52), 0, 0x200u);
  v6 = *(FILE **)(a1 + 209696);
  *(_DWORD *)(a1 + 205560) = 0;
  *(_DWORD *)(a1 + 209692) = 0;
  if ( v6 )
  {
    fclose(v6);
    *(_DWORD *)(a1 + 209696) = 0;
    httpd_release_caches();
  }
  v7 = *(void **)(a1 + 209700);
  if ( v7 )
  {
    _mem_free(v7);
    *(_DWORD *)(a1 + 209700) = 0;
  }
  *(_DWORD *)(a1 + 209704) = 0;
  memset((void *)(a1 + 209708), 0, 0x80u);
  *(_DWORD *)(a1 + 205556) = a1;
  *(_DWORD *)(a1 + 209836) = 0;
  *(_DWORD *)(a1 + 205548) = jiffies_get() + 30000;
  v8 = a1 + 205540;
  *(_DWORD *)(a1 + 205552) = httpd_keep_alive_timeout;
LABEL_15:
  add_timer(v8);
  httpd_conn_epoll_read(a1);
  return 0;
}
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A896C: using guessed type int __fastcall del_timer(_DWORD);

