#!/bin/bash
export MODEL=models/${m:-bert-tiny}
echo ${MODEL}
if [ $m == "bert-tiny" ]; then
    echo "yes, let's use tiny model"
else
    echo "no, let's use base model"
fi
