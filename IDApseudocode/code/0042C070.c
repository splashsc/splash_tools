int __fastcall setnonblocking(int a1)
{
  int v1; // $v0

  v1 = fcntl(a1, 3, 0);
  return -(fcntl(a1, 4, v1 | 0x80) == -1);
}

