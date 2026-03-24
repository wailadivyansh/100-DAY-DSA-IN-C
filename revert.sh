#!/bin/bash

commits=(
  f14eedc 4fb8961 3071f51 1fdd4b4 1d8be5f c7a3fb2 543239d 6e51209
  cd6d0d7 cf134f8 db7bb6a c52d64c a40bb18 49c45c0 ea85423 96ca83f
  0811217 b533777 976789a 0961c73 80fd01f 3b39536
)

for commit in "${commits[@]}"; do
  git revert $commit --no-commit
done

git commit -m "revert april commits"
git push origin main --force