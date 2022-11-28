int check_net()
{
  int v0; // $v0
  unsigned int v1; // $s0
  int v2; // $s1
  int *v4; // $v0
  char *v5; // $v0
  struct sockaddr *v6; // $v0
  char *v7; // $a2
  int *v8; // $s1
  int v9; // $a0
  int v10; // $v0
  int v11; // $v0
  fd_set v12; // [sp+20h] [-11Ch] BYREF
  char v13[128]; // [sp+A0h] [-9Ch] BYREF
  struct sockaddr v14; // [sp+120h] [-1Ch] BYREF
  struct timeval timeout; // [sp+130h] [-Ch] BYREF

  v0 = socket(2, 2, 0);
  v1 = v0;
  if ( v0 >= 0 )
  {
    if ( setnonblocking(v0) >= 0 )
    {
      v14.sa_family = 2;
      *(_WORD *)v14.sa_data = htons(0x35u);
      *(_DWORD *)&v14.sa_data[6] = 0;
      *(_DWORD *)&v14.sa_data[10] = 0;
      *(_DWORD *)&v14.sa_data[2] = inet_addr("114.114.114.114");
      if ( connect(v1, &v14, 0x10u) )
      {
        if ( *_errno_location() != 150 )
        {
          v2 = 0;
          v4 = _errno_location();
          v5 = strerror(*v4);
          printf("connect error :%s\n", v5);
          goto LABEL_5;
        }
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;
        v6 = (struct sockaddr *)v13;
        do
        {
          v6 = (struct sockaddr *)((char *)v6 + 4);
          *(_DWORD *)&v6[-1].sa_data[10] = 0;
        }
        while ( v6 != &v14 );
        v7 = (char *)&v12;
        do
        {
          v7 += 4;
          *((_DWORD *)v7 - 1) = 0;
        }
        while ( v7 != v13 );
        v8 = &v12.__fds_bits[v1 >> 5];
        v9 = 1 << (v1 & 0x1F);
        v10 = *v8 | v9;
        v8[32] |= v9;
        *v8 = v10;
        if ( select(v1 + 1, &v12, (fd_set *)v7, 0, &timeout) == 1 && (((unsigned int)v8[32] >> (v1 & 0x1F)) & 1) != 0 )
        {
          v11 = fcntl(v1, 3, 0);
          fcntl(v1, 4, v11 & 0xFFFFFF7F);
          v2 = 1;
          goto LABEL_5;
        }
      }
    }
    v2 = 0;
LABEL_5:
    close(v1);
    return v2;
  }
  perror("socket");
  v2 = 0;
  if ( v1 != -1 )
    goto LABEL_5;
  return 0;
}

