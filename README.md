# push_swap

42 Common Core の課題。ランダムな整数列を2つのスタック（`a`, `b`）だけを使って、限られた命令セット（`push`, `swap`, `rotate`, `reverse rotate` 等）で昇順にソートするアルゴリズムを実装しました。

## 実装内容

- **Mandatory**: 引数として渡された整数列を最小の命令数に近づけてソートし、命令列を標準出力に出力する `push_swap`
- **Bonus**: `push_swap` が出力した命令列を実際にスタックへ適用し、ソートが正しく行われたか検証する `checker`
- ソート戦略はチャンク分割（`util_find_chunk.c`）とpivotベースの並び替え（`alg_moriP_sort.c`）を組み合わせて実装

## Build & Run

```sh
make          # push_swap をビルド
make bonus    # checker をビルド

./push_swap 2 1 3 6 5 8      # 命令列を出力
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8   # ソート結果を検証（OK/KO）
```

## 技術ポイント

- 大きい入力（500個規模）でも少ない命令数で収束させるため、スタックを一定サイズのチャンクに分割してソートするアルゴリズムを採用
- 数値の重複・オーバーフロー・不正引数（数字以外の文字列など）をパース段階でエラー処理
