int __fastcall asp_activeroutes(char *a1, int a2)
{
  int v4; // $s4
  FILE *v5; // $s1
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $v0
  char *v9; // $a3
  int v10; // $v0
  int v11; // $s3
  int v12; // $v0
  char *v14; // [sp+1Ch] [-28Ch]
  char v15[512]; // [sp+30h] [-278h] BYREF
  char v16[20]; // [sp+230h] [-78h] BYREF
  char v17; // [sp+244h] [-64h] BYREF
  __int16 v18[8]; // [sp+254h] [-54h] BYREF
  int v19[4]; // [sp+264h] [-44h] BYREF
  int v20; // [sp+274h] [-34h] BYREF
  struct in_addr v21; // [sp+278h] [-30h] BYREF
  int v22; // [sp+27Ch] [-2Ch] BYREF
  struct in_addr v23; // [sp+280h] [-28h] BYREF
  struct in_addr in; // [sp+284h] [-24h] BYREF
  int v25; // [sp+288h] [-20h]
  char *format; // [sp+28Ch] [-1Ch]
  char *v27; // [sp+290h] [-18h]
  int v28; // [sp+294h] [-14h]
  char *dest; // [sp+298h] [-10h]
  __int16 *v30; // [sp+29Ch] [-Ch]
  int *v31; // [sp+2A0h] [-8h]

  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  v5 = fopen("/proc/net/route", "r");
  if ( v5 )
  {
    format = "%s{\"dev\":\"%s\",\"dst\":\"%s\",\"gw\":\"%s\",\"mask\":\"%s\",\"met\":%u}";
    v27 = "a";
    v25 = 0;
    v28 = 1634100580;
    while ( fgets(v15, 512, v5) )
    {
      while ( sscanf(v15, "%16s%x%x%x%*s%*s%u%x", v16, &in, &v23, &v22, &v20, &v21) == 6
           && (v22 & 1) != 0
           && !strstr(v16, "wssocks") )
      {
        if ( in.s_addr )
        {
          v6 = inet_ntoa(in);
          v31 = v19;
          strcpy((char *)v19, v6);
        }
        else
        {
          v31 = v19;
          v19[0] = v28;
          v19[1] = 7629941;
        }
        if ( v23.s_addr )
        {
          v7 = inet_ntoa(v23);
          v30 = v18;
          strcpy((char *)v18, v7);
        }
        else
        {
          v30 = v18;
          v18[0] = 42;
        }
        dest = &v17;
        v8 = inet_ntoa(v21);
        strcpy(dest, v8);
        if ( v25 )
          v9 = v27 + 15692;
        else
          v9 = "";
        v14 = dest;
        dest = (char *)(a2 - v4);
        v10 = snprintf(&a1[v4], a2 - v4, format, v9, v16, v31, v30, v14, v20);
        if ( v10 >= (int)dest )
          v10 = (int)(dest - 1);
        v4 += v10;
        ++v25;
        if ( !fgets(v15, 512, v5) )
          goto LABEL_18;
      }
    }
LABEL_18:
    fclose(v5);
  }
  v11 = a2 - v4;
  v12 = snprintf(&a1[v4], v11, &byte_6445A0);
  if ( v12 >= v11 )
    v12 = v11 - 1;
  return v4 + v12;
}
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;

