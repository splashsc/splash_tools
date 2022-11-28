void __fastcall get_client_info(int a1, int a2, int a3)
{
  FILE *v6; // $s3
  char v7[256]; // [sp+10h] [-138h] BYREF
  char v8[20]; // [sp+110h] [-38h] BYREF

  if ( !*(_BYTE *)a3 )
  {
    v6 = fopen("/proc/net/arp", "r");
    if ( v6 )
    {
      while ( fgets(v7, 256, v6)
           && (sscanf(v7, "%15s %*s %*s %17s %*s %16s", v8, a1, a2) != 3 || inet_addr(v8) != *(_DWORD *)(a3 + 4)) )
        ;
      fclose(v6);
    }
  }
}

