void __fastcall websocket_recv_data(_BYTE *a1, int a2, _BYTE *a3, unsigned int a4)
{
  unsigned int v5; // $v0
  _BYTE *v8; // $s0
  _BYTE *v9; // $t2
  _BYTE *v10; // $a2
  _BYTE *v11; // $t0
  _BYTE *v12; // $a3
  int v13; // $v1
  _BYTE *v14; // $a1
  int v15; // $v0
  _BYTE *v16; // t1

  if ( (unsigned __int8)(*a1 + 127) < 2u && a2 >= 6 )
  {
    v5 = a1[1] & 0x7F;
    v8 = a1;
    if ( v5 >= 0x7E )
    {
      if ( v5 == 126 )
      {
        v5 = ntohs(((unsigned __int8)a1[3] << 8) | (unsigned __int8)a1[2]);
        if ( a2 - 8 < v5 )
          return;
        v9 = v8 + 4;
      }
      else
      {
        BYTE2(v15) = a1[8];
        HIBYTE(v15) = a1[9];
        v16 = a1 + 4;
        BYTE2(a1) = a1[4];
        HIBYTE(a1) = v16[1];
        LOWORD(v15) = *((_WORD *)v8 + 3);
        if ( v15 )
          return;
        LOWORD(a1) = *((_WORD *)v8 + 1);
        v5 = ntohl((uint32_t)a1);
        if ( a2 - 14 < v5 )
          return;
        v9 = v8 + 10;
      }
    }
    else
    {
      if ( a2 - 6 < v5 )
        return;
      v9 = a1 + 2;
    }
    if ( v5 >= a4 )
      v5 = a4 - 1;
    v10 = &a3[v5];
    if ( v5 )
    {
      v11 = v9 + 4;
      v12 = a3;
      v13 = 0;
      do
      {
        v14 = &v9[v13++ & 3];
        *v12++ = *v14 ^ *v11++;
      }
      while ( v5 != v13 );
      v10 = &a3[v5];
    }
    *v10 = 0;
  }
}

