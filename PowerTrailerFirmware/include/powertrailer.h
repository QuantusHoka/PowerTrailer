#ifndef POWERTRAILER_H
#define POWERTRAILER_H

#include <Arduino.h>


class AveragingBuffer
{
    public:
    AveragingBuffer(int t_size);
    ~AveragingBuffer(void);
    float avg(void);
    int add(float t_measurement);

    private:
    int m_size;
    int m_index = 0;
    float *m_data = nullptr;
};

AveragingBuffer::AveragingBuffer(int t_size)
{
    m_size = t_size;
    m_index = 0;
    m_data = new float[m_size];
    if (!m_data)
    {
        log_e("Failed to allocate memory");
    }
    else
    {
        for (int cnt=0; cnt<m_size; cnt++)
        {
            m_data[cnt] = 0;
        }
    }
}

AveragingBuffer::~AveragingBuffer(void)
{
    delete[] m_data;
}

int AveragingBuffer::add(float t_measurement)
{
    int result = 0;
    m_data[m_index] = t_measurement;
    m_index++;
    if (m_index >= m_size)
    {
        m_index = 0;
        result = 1;
    }
    return result;
}

float AveragingBuffer::avg(void)
{
    float result = 0;
    for (int cnt = 0; cnt < m_size; cnt++)
    {
        result += m_data[cnt];
    }
    result /= m_size;
    return result;
}












#endif