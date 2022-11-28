unsigned int __fastcall FBR_MD5Final(unsigned int *a1)
{
  int v1; // $a1
  unsigned int v2; // $v0
  unsigned int v4; // $a2
  unsigned __int8 *v5; // $a2
  int *v6; // $a3
  unsigned int *v7; // $s0
  unsigned int *v8; // $s1
  unsigned int *v9; // $a0
  unsigned int result; // $v0
  char v11; // [sp+18h] [-44h] BYREF
  int v12[3]; // [sp+50h] [-Ch] BYREF

  v1 = a1[1];
  v2 = (*a1 >> 3) & 0x3F;
  v12[0] = *a1;
  v12[1] = v1;
  if ( v2 >= 0x38 )
    v4 = 120 - v2;
  else
    v4 = 56 - v2;
  FBR_MD5Update(a1, (int)&unk_66B5A0, v4);
  v5 = (unsigned __int8 *)a1 + 26;
  v6 = (int *)&v11;
  do
  {
    *v6++ = (v5[1] << 24) | (*v5 << 16) | *(v5 - 2) | (*(v5 - 1) << 8);
    v5 += 4;
  }
  while ( v6 != v12 );
  v7 = a1 + 2;
  ((void (__fastcall *)(unsigned int *))loc_42FE80)(a1 + 2);
  v8 = a1 + 6;
  v9 = v7;
  do
  {
    result = *v9++;
    v9[19] = result;
  }
  while ( v8 != v9 );
  return result;
}

