
void bfreeSafe(int param_1)

{
  if (param_1 != 0) {
    bfree();
    return;
  }
  return;
}

