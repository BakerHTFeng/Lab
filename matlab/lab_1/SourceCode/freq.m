function result = freq( img )
%FREQ �Ҷ�Ƶ��ת��
%   ����һ��ͼ�񣬷��ظ�ͼ�����С�Ҷȵ����Ҷȣ������Ҷȼ����ֵĴ���
    gray_min = min(img(:));
    gray_max = max(img(:));
    n = double(gray_max - gray_min) + 1;
    result = zeros(1,n - 1);
    for i = 0 :n - 1
        result(1,i + 1) = numel(find(img == (i + gray_min)));
    end
end

