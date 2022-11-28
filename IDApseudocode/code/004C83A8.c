int __fastcall sub_4C83A8(int a1)
{
  char *v1; // $v0
  const char *v3; // $s0
  int result; // $v0
  void *v5; // $a0
  int v6; // $v0
  void *v7; // $a0
  int v8; // $v0
  int v9; // $a3
  int *v10; // $v0
  int v11; // $a2
  int v12; // $a1
  int v13; // $v1
  char v14; // $v0
  int v15[4]; // [sp+18h] [-218h] BYREF
  char v16; // [sp+28h] [-208h]
  int v17[6]; // [sp+218h] [-18h] BYREF

  v17[0] = (int)"echo";
  v17[1] = 0;
  v17[2] = 0;
  v17[3] = 0;
  v17[4] = 0;
  v17[5] = 0;
  v1 = httpd_get_parm(a1, "id");
  v3 = v1;
  if ( v1 && *v1 && !strchr(v1, 38) && !strchr(v3, 124) && !websocket_respond_head(a1) )
  {
    v5 = *(void **)(a1 + 210016);
    if ( v5 )
    {
      _mem_free(v5);
      *(_DWORD *)(a1 + 210016) = 0;
    }
    *(_DWORD *)(a1 + 210024) = 0;
    _mem_malloc(102400, "websocket_console_cgi", 2494);
    *(_DWORD *)(a1 + 210016) = v6;
    if ( !v6 )
      goto LABEL_20;
    v7 = *(void **)(a1 + 210020);
    if ( v7 )
    {
      _mem_free(v7);
      *(_DWORD *)(a1 + 210020) = 0;
    }
    *(_DWORD *)(a1 + 210028) = 0;
    _mem_malloc(102400, "websocket_console_cgi", 2509);
    *(_DWORD *)(a1 + 210020) = v8;
    if ( v8 )
    {
      if ( !eval_nowait_tty(v3, v17, a1 + 205420, a1 + 205456) && *(int *)(a1 + 205420) >= 0 )
      {
        result = httpd_conn_epoll_add_pty((_DWORD *)a1);
        if ( !result )
        {
          *(_DWORD *)(a1 + 205560) = websocket_console_do_rcv;
          *(_BYTE *)(a1 + 41) = 9;
          return result;
        }
      }
      v9 = 1919250543;
      v10 = &dword_650CA4;
    }
    else
    {
LABEL_20:
      v9 = 1819042157;
      v10 = &dword_650C90;
    }
    v11 = v10[1];
    v12 = v10[2];
    v13 = v10[3];
    v14 = *((_BYTE *)v10 + 16);
    v15[1] = v11;
    v15[2] = v12;
    v15[0] = v9;
    v15[3] = v13;
    v16 = v14;
    websocket_send_data(a1, (int)v15, 16);
  }
  return httpd_conn_close((int *)a1);
}
// 4C8500: variable 'v6' is possibly undefined
// 4C8558: variable 'v8' is possibly undefined
// 650C90: using guessed type int dword_650C90;
// 650CA4: using guessed type int dword_650CA4;
// 6A81E0: using guessed type int __fastcall eval_nowait_tty(_DWORD, _DWORD, _DWORD, _DWORD);

