# 📚 Page Replacement Algorithm — OS Lab Notes

> **Operating System Lab Exam Preparation**

---

## 📌 Table of Contents
- [Page কী?](#page-কী)
- [Page Replacement Algorithm কেন Use করা হয়?](#page-replacement-algorithm-কেন-use-করা-হয়)
- [Page Replacement Algorithm কয় ধরনের?](#page-replacement-algorithm-কয়-ধরনের)
- [Page Fault কী?](#page-fault-কী)
- [Page Hit কী?](#page-hit-কী)
- [FIFO vs OPT vs LRU — কোনটা ভালো?](#fifo-vs-opt-vs-lru--কোনটা-ভালো)

---

## 🗂️ Page কী?

যখন OS একটা program চালায়, তখন সেই program-এর **memory-কে ছোট ছোট টুকরায় ভাগ করা হয়।**
এই প্রতিটা ছোট টুকরাকেই বলে — **PAGE**

### উদাহরণ:
> ধরো একটা বই আছে যেটা 100 পৃষ্ঠার।
> তুমি একসাথে পুরো বই পড়ো না — দরকার অনুযায়ী একটা একটা পৃষ্ঠা পড়ো।

| বিষয় | Real Life | OS |
|-------|-----------|-----|
| বই | Program | Program Memory |
| পৃষ্ঠা | **Page** | **Page** |
| পড়ার টেবিল | RAM | RAM |
| বইয়ের শেলফ | Hard Disk | Hard Disk |

### Technical তথ্য:

| বিষয় | মানে |
|-------|------|
| **Page** | Program-এর memory-র ছোট fixed-size টুকরা |
| **Page Size** | সাধারণত 4KB হয় |
| **Page Table** | কোন page কোথায় আছে তার তালিকা |
| **Page Fault** | দরকারি page RAM-এ নেই — Hard Disk থেকে আনতে হবে |

---

## ❓ Page Replacement Algorithm কেন Use করা হয়?

### মূল কারণ — Virtual Memory

Computer-এ **RAM (Physical Memory) সীমিত**, কিন্তু আমরা অনেক বড় program চালাতে চাই।
তাই OS **Virtual Memory** ব্যবহার করে — প্রয়োজন অনুযায়ী RAM-এ page আনে।

### সমস্যা কখন হয়?

যখন —
- RAM **পূর্ণ** হয়ে যায়
- নতুন একটা **page দরকার** হয়
- কিন্তু RAM-এ **জায়গা নেই**

এই অবস্থাকে বলে **Page Fault** ➡️ তখন OS-কে সিদ্ধান্ত নিতে হয় — **কোন page-টা RAM থেকে বের করে দেব?**

এই সিদ্ধান্ত নেওয়ার জন্যই **Page Replacement Algorithm** ব্যবহার হয়।

---

## 🔄 Page Replacement Algorithm কয় ধরনের?

মূলত **৬ ধরনের** Page Replacement Algorithm আছে:

### 1. 🔵 FIFO (First In First Out)
- সবার আগে যে page এসেছে, সেটা আগে replace হবে
- Queue-এর মতো কাজ করে
- **Belady's Anomaly** হতে পারে

### 2. 🟢 OPT / Optimal Algorithm
- ভবিষ্যতে যে page সবচেয়ে দেরিতে use হবে, সেটা replace করে
- সবচেয়ে কম page fault দেয়
- Practical না (future জানা যায় না)

### 3. 🟡 LRU (Least Recently Used)
- সবচেয়ে কম সম্প্রতি ব্যবহৃত page replace হয়
- Most popular in real systems

### 4. 🟠 LFU (Least Frequently Used)
- সবচেয়ে কম বার use হওয়া page replace হয়

### 5. 🔴 MFU (Most Frequently Used)
- সবচেয়ে বেশি বার use হওয়া page replace হয়

### 6. 🟣 Second Chance / Clock Algorithm
- FIFO-র modified version
- Reference bit দেখে সিদ্ধান্ত নেয়
- Page-কে second chance দেওয়া হয়

### 📊 Quick Summary Table

| # | Algorithm | Full Form | Replace করে |
|---|-----------|-----------|-------------|
| 1 | FIFO | First In First Out | সবচেয়ে পুরনো page |
| 2 | OPT | Optimal | সবচেয়ে দেরিতে দরকার হবে এমন page |
| 3 | LRU | Least Recently Used | সবচেয়ে কম সম্প্রতি ব্যবহৃত |
| 4 | LFU | Least Frequently Used | সবচেয়ে কম বার ব্যবহৃত |
| 5 | MFU | Most Frequently Used | সবচেয়ে বেশি বার ব্যবহৃত |
| 6 | Clock | Second Chance | FIFO + reference bit check |

---

## ❌ Page Fault কী?

> CPU যে page চাইলো — সেটা **RAM-এ নেই**, Hard Disk-এ আছে

### তখন যা হয়:
1. OS বুঝতে পারে page নেই
2. Hard Disk থেকে page আনে
3. RAM-এ জায়গা না থাকলে — **Page Replacement** করে
4. নতুন page RAM-এ load করে
5. তারপর CPU কাজ করে

### উদাহরণ:
> তুমি পড়ার টেবিলে বই খুঁজছো,
> **টেবিলে নেই — শেলফ থেকে আনতে হবে** = Page Fault ❌

---

## ✅ Page Hit কী?

> CPU যে page চাইলো — সেটা **RAM-এ পাওয়া গেল**

- Extra কাজ লাগলো না
- Hard Disk থেকে আনতে হলো না
- **Fast ⚡**

### উদাহরণ:
> তুমি পড়ার টেবিলে বই খুঁজছো,
> **টেবিলেই পেয়ে গেলে** = Page Hit ✅

---

## 📊 Page Hit vs Page Fault

| বিষয় | Page Hit | Page Fault |
|-------|----------|------------|
| Page কোথায় | RAM-এ আছে ✅ | RAM-এ নেই ❌ |
| Speed | দ্রুত ⚡ | ধীর 🐢 |
| Hard Disk | লাগে না | লাগে |
| Replacement | হয় না | হতে পারে |
| Performance | ভালো | খারাপ |

### Hit Ratio Formula:

```
Hit Ratio = Page Hit / (Page Hit + Page Fault)
```

> **Hit Ratio যত বেশি = System তত ভালো** 🏆

---

## 🏆 FIFO vs OPT vs LRU — কোনটা ভালো?

### সরাসরি উত্তর:
- **OPT** — সবচেয়ে ভালো theoretically
- **LRU** — সবচেয়ে ভালো practically ✅

### তুলনামূলক বিশ্লেষণ:

| বিষয় | FIFO | OPT | LRU |
|-------|------|-----|-----|
| **Page Fault** | বেশি | সবচেয়ে কম | কম |
| **Speed** | Fast | Fast | Moderate |
| **Implement করা** | সহজ | অসম্ভব | মোটামুটি কঠিন |
| **Real-world Use** | কম | না | হ্যাঁ ✅ |
| **Belady's Anomaly** | হয় ❌ | হয় না ✅ | হয় না ✅ |

### কেন FIFO দুর্বল?
- শুধু **কতক্ষণ ধরে আছে** সেটা দেখে
- **কতবার use হচ্ছে** সেটা দেখে না
- Belady's Anomaly হয় — frame বাড়ালেও page fault বাড়তে পারে 😱

### কেন OPT সেরা কিন্তু Practical না?
- **ভবিষ্যৎ জানে** — কোন page পরে লাগবে সেটা দেখে সিদ্ধান্ত নেয়
- কিন্তু **OS আগে থেকে future জানতে পারে না!**
- তাই শুধু **benchmark/comparison** এর জন্য use হয়

### কেন LRU Best Practical Choice?
- **সম্প্রতি যা use হয়েছে, ভবিষ্যতেও তা লাগবে** — এই logic কাজ করে
- OPT-এর কাছাকাছি result দেয়
- **Linux, Windows** সহ বেশিরভাগ OS এটা use করে

### Final Verdict:

```
Theoretical Best  →  OPT
Practical Best    →  LRU  ✅
Simplest          →  FIFO
```

---

> 📝 **Note:** Page Fault কমানোই Page Replacement Algorithm-এর মূল লক্ষ্য!

---

*OS Lab Exam Notes | Page Replacement Algorithm*
