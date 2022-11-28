int __fastcall httpd_proxy_xconnect(const struct sockaddr *a1)
{
  int v2; // $v0
  int v3; // $a0
  int v4; // $s0
  int v5; // $v0
  int v7[3]; // [sp+20h] [-Ch] BYREF

  v2 = socket(2, 2, 0);
  v3 = -1;
  if ( v2 >= 0 )
  {
    v4 = v2;
    if ( setblocking(v2) < 0 )
    {
      close(v4);
      v3 = -1;
    }
    else
    {
      v7[0] = 1;
      v7[1] = 0;
      setsockopt(v4, 0xFFFF, 4101, v7, 8u);
      setsockopt(v4, 0xFFFF, 4102, v7, 8u);
      v5 = connect(v4, a1, 0x10u);
      v3 = v4;
      if ( v5 < 0 )
      {
        close(v4);
        v3 = -1;
      }
    }
  }
  return v3;
}

