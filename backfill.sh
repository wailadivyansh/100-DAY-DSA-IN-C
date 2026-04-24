#!/bin/bash

DATES=(
  "2026-04-24" "2026-04-25" "2026-04-26" "2026-04-27" "2026-04-28" "2026-04-29"
)

for DATE in "${DATES[@]}"; do
  echo "update $DATE" >> log.txt
  git add .
  GIT_AUTHOR_DATE="${DATE}T12:00:00" GIT_COMMITTER_DATE="${DATE}T12:00:00" git commit -m "daily update: $DATE"
done
