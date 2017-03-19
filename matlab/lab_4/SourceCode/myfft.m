function result = myfft( list )
%MYFFT ���ٸ���Ҷ�任
%   ��N=2^nʱ�����ݹ�ʽ���ټ�����ٸ���Ҷ�任�Ľ��
    N = length(list);
    % �ݹ鵽1��ʼ���ؽ��
    if N == 1
        result = list;
        return;
    end
    % myfft���� �õݹ�ʵ��
    M = N/2;
    Wn = exp(-1i*2*pi/N).^(0:M-1);
    n = 1:M;
    % �ݹ����
    res_even(n) = myfft(list(2*n-1));
    res_odd(n) = myfft(list(2*n)); 
    % �����Ϊǰ��������
    result = [res_even+res_odd.*Wn res_even-res_odd.*Wn];
end
