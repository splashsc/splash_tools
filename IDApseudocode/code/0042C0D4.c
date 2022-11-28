int __fastcall setblocking(int a1)
{
  int v1; // $v0

  v1 = fcntl(a1, 3, 0);
  return -(fcntl(a1, 4, v1 & 0xFFFFFF7F) == -1);
}

