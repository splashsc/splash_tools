int __fastcall usb_get_current_device(int a1)
{
  FILE *v2; // $v0
  FILE *v3; // $s1
  int v4; // $s5
  char v6[256]; // [sp+18h] [-200h] BYREF
  char v7[256]; // [sp+118h] [-100h] BYREF

  memset(v7, 0, sizeof(v7));
  memset(v6, 0, sizeof(v6));
  strcpy(v6, "/tmp/mnt/sda1/");
  if ( *(unsigned __int16 *)"1/" << 16 >> 24 == 47 )
    v6[13] = 0;
  jhl_system("df > /tmp/df_file");
  v2 = fopen("/tmp/df_file", "r");
  v3 = v2;
  if ( v2 )
  {
    fgets(v7, 256, v2);
    memset(v7, 0, sizeof(v7));
    v4 = -1;
    while ( fgets(v7, 256, v3) )
    {
      if ( strstr(v7, v6) )
      {
        sscanf(v7, "%s", a1);
        v4 = 0;
      }
    }
    fclose(v3);
  }
  else
  {
    v4 = -1;
  }
  remove("/tmp/df_file");
  return v4;
}
// 6A8594: using guessed type int __fastcall jhl_system(_DWORD);

