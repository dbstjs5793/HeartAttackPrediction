# Heart Attack Prediction  

  
## 개요
이 프로젝트는 AVR 보드를 활용하여 심장병 여부를 예측하는 프로그램입니다.  
사용자로부터 환자의 데이터를 입력받아 심장병 여부를 진단합니다.

## 기술 스택
- **AVR 보드**
- **VSPE**와 **PuTTY**를 사용한 **UART 통신**
- **Scikit-learn**, **PyTorch**를 활용한 모델 구축 및 성능 최적화

## Design method
<img src="https://github.com/user-attachments/assets/153e74a2-2aa6-4072-95fe-a22f9e3e4898" width="300">

 - 본 프로젝트에서는 method2를 사용하므로 사용할 데이터셋이 Libsvm 포멧이면 sklearn-svm의 포멧으로 변환해줘야함
   
   <img src="https://github.com/user-attachments/assets/455b0222-e941-482e-9ca6-508791ad1dee" width="400">

  
 - AVR보드와 UART 통신을 하기 위해 C++ code로 convert한 후, C로 수정해줘야함

## method2 기본 예제

### 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. Visual Studio 에서 test => Output : string
5. AVR 에서 test => Output : led

### 예제 코드
- `convert_svm.py` : 학습된 머신러닝 모델(SVM)을 C 코드로 변환하여 저장
  
  <img src="https://github.com/user-attachments/assets/02391f7a-9b74-4580-b860-b873065ee487" width="500">

- `model_linear.h` `model_poly.h` `model_rbf.h` `model_sigmoid.h` :  
  convert_svm.py를 통해 저장된 C++ 코드의 모델, 이를 C로 수정해주어야함

  <img src="https://github.com/user-attachments/assets/6f1da94a-8303-4720-adda-5ca8a1f7d413" width="500">
  <img src="https://github.com/user-attachments/assets/aded42e5-580d-4d47-bb60-73768f60edcc" width="500">

  
- `svm_test_VS.c` :  Visual Studio 에서 test하는 코드
  <img src="https://github.com/user-attachments/assets/3a40dd4e-66dc-473e-a7d4-9aa516ce5ab8" width="500">

- `svm_avr_linear.c` `svm_avr_poly.c` `svm_avr_rab.c` `svm_avr_sig.c` : AVR 에서 test하는 코드
  <img src="https://github.com/user-attachments/assets/5e90537e-8ddb-42bc-8c3b-b79d14566197" width="500">


## 심장병 예측 프로젝트

### 전체 흐름도
1. Python에서 svm train
2. Micromlgen librar로 C++ code로 convert
3. C++로 convert된 함수를C로다듬기
4. UART 통신을 통해 환자의 데이터(predict data) 전송
5. AVR 에서 test => Output 출력

    <img src="https://github.com/user-attachments/assets/74fac48d-7d01-47f6-a5b2-0ec5f9e8bd3b" width="500">

### Datasets
<img src="https://github.com/user-attachments/assets/bc21c538-321c-4158-8fa6-43ba957f733f" width="500">
<br>
<img src="https://github.com/user-attachments/assets/7b9d21ba-f7aa-4be4-9795-ba5c02cf9f4a" width="400">
<br>
<img src="https://github.com/user-attachments/assets/8a053fb7-da5e-4d59-a76c-eae31628c0f0" width="400">


### 프로젝트 코드
- `heart_model_poly.h`: 심장병 예측 모델
- `data/`: Kaggle 데이터셋
- `README.md`: 프로젝트 설명

### 참고 사이트
- Kaggle : https://www.kaggle.com/search?q=svm+in%3Adatasets
- Add jetbrain edu : https://www.jetbrains.com/pycharm-edu/
- Download pycharm : https://www.jetbrains.com/pycharm/
- Download anaconda : https://www.anaconda.com/docs/getting-started/anaconda/install
  
## 라이선스
MIT License
