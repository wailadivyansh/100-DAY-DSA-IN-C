#!/bin/bash

DATES=(
  "2026-04-09" "2026-04-10" "2026-04-11" "2026-04-12" "2026-04-13"
  "2026-04-14" "2026-04-15" "2026-04-16" "2026-04-17" "2026-04-18"
  "2026-04-19" "2026-04-20" "2026-04-21"
)

for DATE in "${DATES[@]}"; do
  echo "update $DATE" >> log.txt
  git add .
  GIT_AUTHOR_DATE="${DATE}T12:00:00" GIT_COMMITTER_DATE="${DATE}T12:00:00" git commit -m "daily update: $DATE"
done

git push origin main --force